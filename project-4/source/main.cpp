#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int> > prs;

int partition(vector<int>& list, int first, int last) 
{
    int mid = first + (last - first) / 2;

    // Choosing pivot as the median of first, middle, and last elements
    int pivot = list[mid];
    swap(list[mid], list[last]); // Move pivot to end

    int smallIndex = first; // Keeps track of the boundary for elements smaller than the pivot
    for (int i = first; i < last; ++i) 
    {
        if (list[i] <= pivot) 
        {
            swap(list[i], list[smallIndex]);
            ++smallIndex;
        }
    }
    swap(list[smallIndex], list[last]); // Move pivot to its correct position
    return smallIndex;
}

void quicksort(vector<int>& list, int first, int last) 
{
  if (first < last)
  {
      int pi = partition(list, first, last);
      quicksort(list, first, pi - 1);
      quicksort(list, pi + 1, last);
  }
}

void multiway_merge(vector<vector<int> >& input_lists, vector<int>& output_list) 
{
  priority_queue<prs, vector<prs>, greater<prs> > p_queue;

  for (size_t i = 0; i < input_lists.size(); i++)
  {
    p_queue.push(make_pair(input_lists[i][0], make_pair(i, 0)));
  }
  
  while (!p_queue.empty())
  {
    prs curr = p_queue.top();
    p_queue.pop();

    int i = curr.second.first;
    int j = curr.second.second;
    
    output_list.push_back(curr.first);

    if (j + 1 < input_lists[i].size())
    {
      p_queue.push(make_pair(input_lists[i][j + 1], make_pair(i, j + 1)));
    }
  }
} 

int main(int argc, char** argv) 
{
    int n, m;
    cin >> n >> m;

    vector<vector<int> > input_lists(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> input_lists[i][j];
        }
    }

    // Quicksort k sublists
    for (int i = 0; i < input_lists.size(); ++i)
        quicksort(input_lists[i], 0, m - 1);

    // Merge n input sublists into one sorted list
    vector<int> output_list;
    multiway_merge(input_lists, output_list);

    for (int i = 0; i < output_list.size(); ++i)
        cout << output_list[i] << " ";
    
    cout << endl;

    return 0;
}