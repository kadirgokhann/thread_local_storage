#include <iostream>
#include <string>
#include <thread>
#include <atomic>

static 			std::atomic<int> 	GlobalStaticVariable = 0;

thread_local 	int 				GlobalTLSVariable = 0;

int incrementStatic()
{
    static std::atomic<int> counter = 0;
    return counter++;
}

int incrementTLS()
{
    thread_local int counter = 0;
    return counter++;
}

void threadProcess(int n)
{
	std::cout << "(Thread" << n << ") 	Global 	Static 	counter " << GlobalStaticVariable++ << std::endl;
    std::cout << "(Thread" << n << ") 	Global 	Static 	counter " << GlobalStaticVariable++ << std::endl;
    std::cout << "(Thread" << n << ") 	Global 	TLS 	counter " << GlobalTLSVariable++ << std::endl;
    std::cout << "(Thread" << n << ") 	Global 	TLS 	counter " << GlobalTLSVariable++ << std::endl;
    std::cout << "(Thread" << n << ") 		Static 	counter " << incrementStatic() << std::endl;
    std::cout << "(Thread" << n << ") 		Static 	counter " << incrementStatic() << std::endl;
    std::cout << "(Thread" << n << ") 		TLS	counter " << incrementTLS() << std::endl;
    std::cout << "(Thread" << n << ") 		TLS	counter " << incrementTLS() << std::endl;
}

int main()
{
    std::cout << "(Main) 		Global 	Static 	counter " << GlobalStaticVariable++ << std::endl;
    std::cout << "(Main) 		Global 	Static 	counter " << GlobalStaticVariable++ << std::endl;
    std::cout << "(Main) 		Global 	TLS 	counter " << GlobalTLSVariable++ << std::endl;
    std::cout << "(Main) 		Global 	TLS 	counter " << GlobalTLSVariable++ << std::endl;
    std::cout << "(Main) 			Static 	counter " << incrementStatic() << std::endl;
    std::cout << "(Main) 			Static 	counter " << incrementStatic() << std::endl;
    std::cout << "(Main) 			TLS	counter " << incrementTLS() << std::endl;
    std::cout << "(Main) 			TLS	counter " << incrementTLS() << std::endl;
    std::cout << "----------------------------" << std::endl;
  	std::thread t(threadProcess, 1);
	t.join();
    std::cout << "----------------------------" << std::endl;
  	std::thread t2(threadProcess, 2);
	t2.join();
    std::cout << "----------------------------" << std::endl;
    std::cout << "(Main) 		Global 	Static 	counter " << GlobalStaticVariable++ << std::endl;
    std::cout << "(Main) 		Global 	Static 	counter " << GlobalStaticVariable++ << std::endl;
    std::cout << "(Main) 		Global 	TLS 	counter " << GlobalTLSVariable++ << std::endl;
    std::cout << "(Main) 		Global 	TLS 	counter " << GlobalTLSVariable++ << std::endl;
    std::cout << "(Main) 			Static 	counter " << incrementStatic() << std::endl;
    std::cout << "(Main) 			Static 	counter " << incrementStatic() << std::endl;
    std::cout << "(Main) 			TLS	counter " << incrementTLS() << std::endl;
    std::cout << "(Main) 			TLS	counter " << incrementTLS() << std::endl;
    return 0;
}
