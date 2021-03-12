#include "pch.h"
#include "CppUnitTest.h"
#include "dll1regex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	static void test_method(std::string mask, std::string result) {
		std::stringstream ss;
		ss << "erer\n";
		ss << "er\n";
		ss << "er\n";
		ss << "er\n";
		ss << "er\n";
		ss << "reger\n";
		ss << "gergreg\n";
		ss << "r\n";
		std::stringstream ss1;
		std::string out;
		regex(ss, mask, ss1);
		ss1.flush();
		out = ss1.str();
		Assert::AreEqual(out, result);
	}

	static void test_method2(std::string mask, std::string result) {
		std::stringstream ss;
		ss << "erer\n";
		ss << "er\n";
		ss << "er\n";
		ss << "er\n";
		ss << "er\n";
		ss << "reger\n";
		ss << "gergreg\n";
		ss << "r\n";
		ss << "erdfdggr\n";
		std::stringstream ss1;
		std::string out;
		regex(ss, mask, ss1);
		ss1.flush();
		out = ss1.str();
		Assert::AreEqual(out, result);
	}

	TEST_CLASS(UnitTest1)
	{
	public:
		
		
		TEST_METHOD(TestMethod1)
		{
			
			test_method(std::string("ger*f"),std::string().append(""));
		}

		TEST_METHOD(TestMethod2)
		{
			test_method(std::string("e*e"), std::string().append(""));
		}
		
		TEST_METHOD(TestMethod3)
		{
			std::string result("er\n");
			result.append("er\n");
			result.append("er\n");
			result.append("er\n");
			test_method(std::string("er"), result);
		}
		
		TEST_METHOD(TestMethod4)
		{
			std::string result("gergreg\n");
			test_method(std::string("ger*g"), result);
		}
		
		TEST_METHOD(TestMethod5)
		{
			std::string result("gergreg\n");
			test_method(std::string("*eg"), result);
		}
		
		TEST_METHOD(TestMethod6)
		{
			std::string result("erer\n");
			result.append("er\n");
			result.append("er\n");
			result.append("er\n");
			result.append("er\n");
			result.append("reger\n");
			result.append("gergreg\n");
			result.append("r\n");
			test_method(std::string("*r*"), result);
		}

		TEST_METHOD(TestMethod7)
		{
			std::string result;
			result.append("reger\n");
			test_method(std::string("r*r"), result);
		}

		TEST_METHOD(TestMethod8)
		{
			std::string result;
			result.append("erer\n");
			result.append("er\n");
			result.append("er\n");
			result.append("er\n");
			result.append("er\n");
			result.append("reger\n");
			result.append("gergreg\n");
			result.append("r\n");
			test_method(std::string("*"), result);
		}

		
		TEST_METHOD(TestMethod9)
		{
			std::string result;
			result.append("gergreg\n");
			test_method(std::string("g*r*"), result);
		}
		
		TEST_METHOD(TestMethod10)
		{
			std::string result;
			result.append("gergreg\n");
			test_method(std::string("g*r**g"), result);
		}
		
		
		TEST_METHOD(TestMethod11)
		{
			std::string result;
			result.append("gergreg\n");
			test_method(std::string("g****r**"), result);
		}

		
		
		
		TEST_METHOD(TestMethod12)
		{
			std::string result("erer\n");
			result.append("er\n");
			result.append("er\n");
			result.append("er\n");
			result.append("er\n");
			result.append("reger\n");
			result.append("gergreg\n");
			test_method(std::string("*e*.*"), result);
		}



	};

	TEST_CLASS(UnitTest2)
	{
	public:


		TEST_METHOD(TestMethod1)
		{
			std::string result;
			result.append("r\n");
			test_method(std::string("."), result);
		}

		TEST_METHOD(TestMethod2)
		{
			std::string result;
			result.append("er\n");
			result.append("er\n");
			result.append("er\n");
			result.append("er\n");
			test_method(std::string(".r"), result);
		}

		TEST_METHOD(TestMethod3)
		{
			std::stringstream ss;
			ss << "erer\n";
			ss << "ere\n";
			ss << "er\n";
			ss << "er\n";
			ss << "er\n";
			ss << "er\n";
			ss << "reger\n";
			ss << "gergreg\n";
			ss << "r\n";
			std::stringstream ss1;
			std::string out;
			regex(ss, std::string("er*."), ss1);
			ss1.flush();
			out = ss1.str();
			std::string result;
			result.append("erer\n");
			result.append("ere\n");
			Assert::AreEqual(out, result);
			
		}

		TEST_METHOD(TestMethod4)
		{
			std::string result;
			result.append("gergreg\n");
			test_method(std::string("*.g"), result);
		}

		TEST_METHOD(TestMethod5)
		{
			std::string result;
			result.append("erer\n");
			result.append("erdfdggr\n");
			test_method2(std::string("e*.r"), result);
		}

		TEST_METHOD(TestMethod6)
		{
			std::string result;
			result.append("reger\n");
			test_method(std::string("reg.r"), result);
		}

		TEST_METHOD(TestMethod7)
		{
			std::string result("");
			test_method(std::string("*g."), result);
		}
	};
}
