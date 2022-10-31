#include <bits/stdc++.h>
using namespace std;

int numLines(string name){
      std::ifstream myfile(name);

    // new lines will be skipped unless we stop it from happening:    
    myfile.unsetf(std::ios_base::skipws);

    // count the newlines with an algorithm specialized for counting:
    unsigned line_count = std::count(
        std::istream_iterator<char>(myfile),
        std::istream_iterator<char>(), 
        '\n');

    std::cout << "Lines: " << line_count << "\n";
    return line_count;
}

string genString(int n){
  string alphanum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  int m = alphanum.size();
  string result = "";
  for (int i = 0; i < n; i++){
    result += alphanum[rand()%(m-1)];
  }
  result += "\n";
  return result;
}

int main(){
  int n = 1000;
  srand(time(NULL));
  fstream in("input.txt");
  for (int i = 0; i < n; i++){
    int m = rand() % 5+1;
    in << genString(m) ;
  }
}
// void solveBase(string inputFile, string outputFile){
//   ifstream in(inputFile);
//   int size = MAX_SIZE;
//   string a[size]; //?
//   ofstream out(outputFile);
//   int i;
//   bool moreInput = true;
//   while (in.is_open() && moreInput)
//   {
//     string line;
//     i = 0;
//     while (i < size){
//       if (!getline(in, line)){
//         moreInput = false;
//         break;
//       }
//       a[i] = line;
//       i++;
//     }
//   }
//   sort(a, a + i);
//   for (int j = 0; j < i; j++){
//     out << (a[j] + "\n");
//   }
//   in.close();
//   out.close();
// }