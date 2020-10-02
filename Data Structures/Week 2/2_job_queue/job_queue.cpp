#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

class Threads
{
public:
	int worker;
	long long int finish_time;
};
/*
struct compare
{
	bool operator()(const Threads &lhs, const Threads &rhs)
	{
		if (lhs.finish_time == rhs.finish_time)
			return lhs.worker > rhs.worker;
		return lhs.finish_time > rhs.finish_time;
	}
};
*/
bool operator>(const Threads &lhs, const Threads &rhs)
{
	if (lhs.finish_time == rhs.finish_time)
		return lhs.worker > rhs.worker;
	return lhs.finish_time > rhs.finish_time;
}
class JobQueue
{
private:
	int num_workers_;
	vector<int> jobs_;

	vector<int> assigned_workers_;
	vector<long long> start_times_;

	void WriteResponse() const
	{
		for (int i = 0; i < jobs_.size(); ++i)
		{
			cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
		}
	}

	void ReadData()
	{
		int m;
		cin >> num_workers_ >> m;
		jobs_.resize(m);
		for (int i = 0; i < m; ++i)
			cin >> jobs_[i];
	}

	void AssignJobs()
	{
		// TODO: replace this code with a faster algorithm.
		assigned_workers_.resize(jobs_.size());
		start_times_.resize(jobs_.size());
		//std::priority_queue<Threads ,vector<Threads> , compare >pq; // Similar to below and compare should be of struct type
		std::priority_queue<Threads, vector<Threads>, std::greater<vector<Threads>::value_type>> pq;
		for (int i = 0; i < num_workers_ && i < jobs_.size(); i++)
		{
			assigned_workers_[i] = i;
			start_times_[i] = 0;
			pq.push(Threads{i, jobs_[i]});
		}
		for (int i = num_workers_; i < jobs_.size(); i++)
		{
			int worker = pq.top().worker;
			long long int start_time = pq.top().finish_time;
			pq.pop();
			assigned_workers_[i] = worker;
			start_times_[i] = start_time;
			pq.push(Threads{worker, start_time + jobs_[i]});
		}
		/*
    vector<long long> next_free_time(num_workers_, 0);
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }
    */
	}

public:
	void Solve()
	{
		ReadData();
		AssignJobs();
		WriteResponse();
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	JobQueue job_queue;
	job_queue.Solve();
	return 0;
}
