typedef unsigned int u8;
typedef char s8;

typedef unsigned int u32;
typedef int s32;

typedef unsigned long long u64;
typedef long long s64;

#define global_variable static
#define internal static

inline int
clamp(int min, int x, int max) {
	return (x < min) ? min : (x > max) ? max : x;
}
