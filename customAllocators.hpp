#include <queue>
#include <sys/mman.h>
#include <limits>

template <typename T>
class QueueAllocator 
{
	public:
		typedef T value_type;
		typedef T* pointer;
		typedef T const * const_pointer;
		typedef T& reference;
		typedef T const & const_reference;
		typedef std::size_t    size_type;
		typedef std::ptrdiff_t difference_type;

		QueueAllocator(void): _block_size(1024) {}

		template <class Type>
		struct rebind
		{
  			typedef QueueAllocator<Type> other;
		};

		pointer address (reference value) const
		{
			return &value;
		}
		const_pointer address (const_reference value) const
		{
			return &value;
		}

		T* allocate(std::size_t n) 
		{
			if (!n)
				return (NULL);
			if (n > max_size())
				throw std::bad_alloc();
			if (_free_list.empty())
			{
				size_t size = _block_size * sizeof(T);
				void* newBlock = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
				if(newBlock == MAP_FAILED)
					throw std::bad_alloc();
				for (std::size_t i = 0; i < _block_size; i += sizeof(T))
					_free_list.push(reinterpret_cast<T*>(newBlock) + i);
			}
			T* res = _free_list.front();
			_free_list.pop();
			return res;
		}

		void deallocate(T* p, std::size_t n)
		{
			static_cast<void>(n);
			_free_list.push(p);
		}

		void construct (pointer p, const_reference val)
		{
			new((void *)p) T(val);
		}

		template <typename U>
		void destroy(U* p)
		{
			p->~U();
		}

		std::size_t max_size() const
		{
			return std::numeric_limits<std::size_t>::max() / sizeof(T);
		}

		~QueueAllocator()
		{
			while(!_free_list.empty())
			{
				munmap(_free_list.front(), _block_size * sizeof(T));
				_free_list.pop();
			}
		}

	private:
		std::queue<T*> _free_list;
		std::size_t _block_size;
};
