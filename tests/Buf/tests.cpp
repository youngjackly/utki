#include "../../src/utki/Buf.hpp"

#include "tests.hpp"


namespace TestStaticBufferCopyConstructor{

class TestClass{
public:
	int a;

	TestClass() :
			a(0)
	{}

	TestClass(const TestClass& c){
		this->a = c.a + 1;
	}

	TestClass& operator=(const TestClass& tc){
		return *this;
	}
};

void Run(){
	typedef std::array<TestClass, 20> T_TestStaticBuffer;
	T_TestStaticBuffer arr;
	T_TestStaticBuffer brr(arr);

	ASSERT_ALWAYS(arr.size() == brr.size())
	for(size_t i = 0; i < arr.size(); ++i){
		ASSERT_ALWAYS(arr[i].a == 0)
		ASSERT_ALWAYS(brr[i].a == 1)
	}
}

}


namespace TestStaticBufferOperatorEquals{

class TestClass{
public:
	size_t id;
	int a;

	TestClass() :
			a(0)
	{}

	TestClass(const TestClass& tc){
		this->a = tc.a + 1;
	}
};

void Run(){
	typedef std::array<TestClass, 20> T_TestStaticBuffer;
	T_TestStaticBuffer arr;

	for(size_t i = 0; i < arr.size(); ++i){
		arr[i].id = i;
	}

	T_TestStaticBuffer brr;
	TestClass* oldArrBegin = &*arr.begin();
	TestClass* oldBrrBegin = &*brr.begin();
	ASSERT_ALWAYS(&*brr.begin() != &*arr.begin())
	
	brr = arr;
	
	ASSERT_ALWAYS(&*brr.begin() != &*arr.begin())
	ASSERT_ALWAYS(&*arr.begin() == oldArrBegin)
	ASSERT_ALWAYS(&*brr.begin() == oldBrrBegin)

	ASSERT_ALWAYS(arr.size() == brr.size())
	for(size_t i = 0; i < arr.size(); ++i){
		ASSERT_ALWAYS(arr[i].a == 0)
		ASSERT_INFO_ALWAYS(brr[i].a == 0, "brr[i].a = " << brr[i].a)
		ASSERT_INFO_ALWAYS(arr[i].id == brr[i].id, "arr[i].id = " << arr[i].id << " brr[i].id = " << brr[i].id)
		ASSERT_ALWAYS(arr[i].id == i)
	}
}

}



namespace TestBufferConstCast{

class TestClass{
public:
	int a;

	TestClass() :
			a(0)
	{}
};


int Func2(const utki::Buf<TestClass> buf){
	if(buf.size() == 0){
		return 0;
	}
	
	return buf[0].a;
}

void Run(){
	{
		std::array<TestClass, 20> buf;
		
//		Func(buf);
		Func2(utki::wrapBuf(buf));
	}
	
	{
		std::vector<TestClass> buf(20);
		
//		Func(buf);
		Func2(utki::wrapBuf(buf));
	}
	
//	Func(ting::Buffer<TestClass>(0, 0));
	Func2(utki::wrapBuf<TestClass>(0, 0));
}

}


namespace testOutputToStream{
void run(){
	{
		std::array<char, 12> buf = {{'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!'}};

		std::stringstream ss;

		ss << utki::wrapBuf(buf);

		ASSERT_ALWAYS(ss.str() == "Hello world!")
	}
	{
		std::array<char, 12> buf = {{'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!'}};
		ASSERT_ALWAYS(toString(utki::wrapBuf(buf)) == "Hello world!")
	}
}
}
