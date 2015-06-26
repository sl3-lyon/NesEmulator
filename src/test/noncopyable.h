#ifndef __noncopyable_h__
#define __noncopyable_h__

namespace std {
	class noncopyable {
		public:
			noncopyable() = default;
			~noncopyable() = default;
		private:
			noncopyable(noncopyable const&) = delete;
			noncopyable& operator=(noncopyable const&) = delete;
	};
} // noncopyable std

#endif // __noncopyable_h__
