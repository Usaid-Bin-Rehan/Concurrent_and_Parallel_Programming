/*
Multithreaded programming is programming multiple, concurrent execution threads.

Concurrent vs Parallel - Multithreaded Programming on a Single Processor:
Multithreading on a single processor gives the illusion of running in parallel. 
In reality, the processor is switching by using a scheduling algorithm. 
Or, it’s switching based on a combination of external inputs (interrupts) and how the threads have been prioritized.

Concurrent vs Parallel - Multithreaded Programming on Multiple Processors:
Multithreading on multiple processor cores is truly parallel. 
Individual microprocessors work together to achieve the result more efficiently. 
There are multiple parallel, concurrent tasks happening at once.
*/

# include <iostream>
# include <thread>

static bool s_Finished = false;

void DoWork(void)
{
	using namespace std::literals::chrono_literals;
	
	std::cout << "Started thread id-" << std::this_thread::get_id() << std::endl;
	
	while(!s_Finished)
	{
		std::cout << "Working..." << std::endl;
		std::this_thread::sleep_for(1s);
	}
}

int main()
{
	std::thread worker(DoWork);
	
	worker.join();
	std::cout << "Finished." << std::endl;
	std::cout << "Started thread id-" << std::this_thread::get_id() << std::endl;
	
	std::cin.get();
}
