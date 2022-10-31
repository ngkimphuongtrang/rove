#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int MAX_SIZE = int(1e5);

// Util Functions
int filesize(string filename){
  std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
  return int(in.tellg());
}

bool isEmpty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

struct MinHeapNode{
  string line;
  int i;
  MinHeapNode(string line, int i){
    this->line = line;
    this->i = i;
  }
  bool operator<(const MinHeapNode& rhs) const{
    return (this->line.compare(rhs.line) > 0);
  }
};

void createInitialRuns(string inputFile, int runSize, int runs)
{
  ifstream in(inputFile);
  ofstream out[runs]; // runs = 0?
  for (int i = 0; i < runs; i++)
  {
    out[i].open("file/" + to_string(i));
  }
  string a[runSize];
  bool moreInput = true;
  int nextOutputFile = 0;
  int i = 0;
  while (in.is_open() && moreInput)
  {
    string line;
    i = 0;
    while (i < runSize){
      if (in.eof()){
        moreInput = false;
        break;
      }
      getline(in, line);
      a[i] = line;
      i++;
    }
    sort(a, a + i);
    for(int j = 0; j < i - 1; j++){
      out[nextOutputFile] << (a[j])<<endl;
    }
    if (i > 0)
    {
      cout << a[i-1] << endl;
      out[nextOutputFile] << a[i-1];
    }
    cout << "Write " << i << " elements to run " << nextOutputFile << endl;
    nextOutputFile++;
  }
  for (int i = 0; i < runs; i++){
    out[i].close();
  }
  in.close();
}

void mergeFiles(string outputFile, int runSize, int runs){
  ifstream in[runs];
  for (int i = 0; i < runs; i++){
    in[i].open("file/" + to_string(i));
  }
  ofstream out(outputFile);

  priority_queue<MinHeapNode, vector<MinHeapNode>> heap;
  int i;
  string line;
  for (i = 0; i < runs; i++){
    if (in[i].eof() || isEmpty(in[i])){
      break;
    } else{
      getline(in[i], line);
      heap.push(MinHeapNode(line, i));
    }
  }
  while (!heap.empty()){
    string line = heap.top().line;
    int index = heap.top().i;
    heap.pop();
    out << line  <<endl;
    if (!in[index].eof()){
      getline(in[index], line);
      heap.push(MinHeapNode(line, index));
    }
  }
  for (int i = 0; i < runs; i++){
    in[i].close();
  }
  out.close();
}

void externalSort(string inputFile, string outputFile, int runs, int runSize){
  createInitialRuns(inputFile, runSize, runs);
  mergeFiles(outputFile, runSize, runs);
}


int main(int argc, char **argv){
  if (argc < 4)
  {
    cout << "Not enough pass arugments\n";
    return 0;
  }
  string inputFile = argv[1];
  string outputFile = argv[2];
  long long memoryLimit = atoi(argv[3]); // bytes
  int fileSize = filesize(inputFile);
  cout << "FileSize:" << fileSize << '\n';
  if (memoryLimit == 0){
    cout << argv[2] << '\n';
    cout << inputFile << " " << outputFile << " " << memoryLimit << '\n';
    cout << "Bad arguments\n";
    return 0;
  }

  long long runSize = memoryLimit;
  if (runSize > MAX_SIZE){
    runSize = MAX_SIZE;
  }
    int runs = fileSize / runSize;
  if (fileSize % runSize > 0){
    runs++;
  }
  srand(time(NULL));
  cout << memoryLimit << " " << runs << " " << runSize << '\n';
  externalSort(inputFile, outputFile, runs, runSize);
}
/*
g++ myfsort2.cpp -o myfsort2 && ./myfsort2 input.txt output.txt 8
*/