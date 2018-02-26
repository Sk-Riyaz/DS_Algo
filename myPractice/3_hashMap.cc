#include<stdio.h>
#include<iostream>

#define DEFAULT_MAX_ARRAY_SIZE 11
#define DEFAULT_MAX_DATA_HOLDING_SIZE_PER_BUCKET 20

template< class T >
class HashMap
{
   // Actual Node which holds the data or Doubly liked list node
   struct Node
   {
      T data;
      struct Node *prev;
      struct Node *next;
      
      Node( T val )
      {
         data = val;
         prev = NULL;
         next = NULL;
      }

      ~Node( )
      {
         data = -1;
         prev = NULL;
         next = NULL;
      }
   };

   // Handling of Doubly linked link
   struct ArrayData
   {
      private:
         size_t mBucketSize; // Total no: of elements in the bucket
         Node *mBucketLink;

         Node *getHead( ) const
         {
            return mBucketLink;
         }

         void setHead( Node *const ptr )
         {
            mBucketLink = ptr;
         }

      public:
         ArrayData()
         {
            mBucketSize = 0;
            mBucketLink = NULL;
         }

         ~ArrayData()
         {
            mBucketSize = 0;
            while( NULL != mBucketLink )
            {
               Node *temp = mBucketLink->next;
               delete mBucketLink;
               mBucketLink = temp;
            }
         }

         size_t size() const
         {
            return mBucketSize;
         }

         void incrementBucketSize( )
         {
            ++mBucketSize;
         }

         void decrementBucketSize( )
         {
            --mBucketSize;
         }

         bool append( T data )
         {
            Node *loopPtr = getHead( );
            while( NULL != loopPtr && NULL != loopPtr->next )
            {
               loopPtr = loopPtr->next;
            }

            Node *node = new Node( data );
            node->prev = loopPtr;
            if( NULL == loopPtr )
            {
               setHead( node );
            }
            else
            {
               loopPtr->next = node;
            }
            incrementBucketSize( );
            return true;
         }

         bool remove( T data )
         {
            Node *loopPtr = getHead( );
            while( NULL != loopPtr && data != loopPtr->data )
            {
               loopPtr = loopPtr->next;
            }

            if( NULL == loopPtr )
            {
               return false;
            }

            if( NULL != loopPtr->prev )
            {
               loopPtr->prev->next = loopPtr->next;
            }
            else
            {
               setHead( loopPtr->next );
            }

            if( NULL != loopPtr->next )
            {
               loopPtr->next->prev = loopPtr->prev;
            }

            decrementBucketSize( );
            delete loopPtr;
            loopPtr = NULL;
            return true;
         }

         const Node *search( T data ) const
         {
            Node *dataPtr = getHead( );
            while( NULL != dataPtr && data != dataPtr->data )
            {
               dataPtr = dataPtr->next;
            }
            return dataPtr;
         }

         void print() const
         {
            Node *loopPtr = getHead( );
            while( NULL != loopPtr )
            {
               std::cout << loopPtr->data;
               loopPtr = loopPtr->next;
            }
            std::cout << std::endl;
         }
   };

   private:
      unsigned int mHashval;
      size_t mSize; // Total number of elements in the hashMap
      ArrayData *arr;

      unsigned int getBucketIndex( T data ) const
      {
         // Define a hash fuction to get a unique value for data
         return data % mHashval;
      }

      // Yet to be implemented
      bool reHash()
      {
         return false;
      }

   public:
      HashMap( )
      {
         mHashval = DEFAULT_MAX_ARRAY_SIZE;
         mSize = 0;
         arr = new ArrayData[mHashval];
      }

      ~HashMap( )
      {
         delete []arr;
         arr = NULL;
      }

      bool insert( const T data )
      {
         const unsigned int bucketIndex = getBucketIndex( data );
         if( arr[bucketIndex].size( ) >=
               DEFAULT_MAX_DATA_HOLDING_SIZE_PER_BUCKET )
         {
            reHash( );
         }

         ArrayData &bucket = arr[bucketIndex];
         bool status = bucket.append( data );
         mSize += status ? 1 : 0;
         return status;
      }

      bool remove( T data )
      {
         const unsigned int bucketIndex = getBucketIndex( data );
         ArrayData &bucket = arr[bucketIndex];
         bool status = bucket.remove( data );
         mSize -= status ? 1 : 0;
         return status;
      }

      const Node *const find( const T data ) const
      {
         const unsigned int bucketIndex = getBucketIndex( data );
         const ArrayData &bucket = arr[bucketIndex];
         return bucket.search( data );
      }

      size_t size() const
      {
         return mSize;
      }

      void print() const
      {
         std::cout << "Total Size: " << mSize << std::endl;
         for( int i = 0; i < DEFAULT_MAX_ARRAY_SIZE; ++i )
         {
            const ArrayData &bucket = arr[i];
            std::cout << i << "-" << bucket.size() << "--> ";
            bucket.print();
         }
      }
};


int main()
{
   // Currently work only for int
   HashMap<int> obj;
   for( int i = 0; i < 100; ++i )
   {
      obj.insert( i );
   }
   obj.print();

   std::cout << obj.find( 10 ) << std::endl;
   for( int i = 0; i < 100; ++i )
   {
      obj.remove( i );
   }

   obj.print();

   
#if 0
   obj.remove( 1 );
   printf("\n");
   obj.print();

   obj.remove( 99 );
   printf("\n");
   obj.print();

   obj.remove( 55 );
   printf("\n");
   obj.print();
#endif
   //printf("%d\n", obj.find(1000)->data);
}
