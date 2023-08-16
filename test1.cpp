#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// Функция для разбиения строки на слова
vector<string> split(const string& s, char delimiter) {
  vector<string> tokens;
  string token;
  istringstream tokenStream(s);
  while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}

// Функция для запуска команды в bash и получения результата
string runCommand(const string& command) {
  string result;
  FILE* pipe = popen(command.c_str(), "r");
  if (pipe) {
    char buffer[128];
    while (!feof(pipe)) {
      if (fgets(buffer, 128, pipe) != NULL) {
        result += buffer;
      }
    }
    pclose(pipe);
  }
  return result;
}

// Функция для выполнения теста
bool runTest(const vector<string>& inputs, const string& expectedOutput) {
  stringstream inputStr;
  for (const string& input : inputs) {
    inputStr << input << " ";
  }
  string command = "./lab1.sh " + inputStr.str();
  string actualOutput = runCommand(command);
  cout << "Actual output:\n\n" << actualOutput << endl << "Expected output:\n\n"<< expectedOutput << endl;
  return actualOutput == expectedOutput;
}

int main() {
  // Тест 1: Проверка работы программы для 3 параметров
  vector<string> test1_inputs = { "param1", "param2", "param3" };
  string test1_expectedOutput = "Цикл while:\nparam3\nparam2\nparam1\n----------------------\nЦикл for:\nparam3\nparam2\nparam1\n";
  bool test1_passed = runTest(test1_inputs, test1_expectedOutput);
  cout << "Test 1: " << (test1_passed ? "Passed\n" : "Failed\n") << endl;

  // Тест 2: Проверка работы программы для 1 параметра
  vector<string> test2_inputs = { "param" };
  string test2_expectedOutput = "Цикл while:\nparam\n----------------------\nЦикл for:\nparam\n";
  bool test2_passed = runTest(test2_inputs, test2_expectedOutput);
  cout << "Test 2: " << (test2_passed ? "Passed\n" : "Failed\n") << endl;

  // Тест 3: Проверка работы программы без параметров
  vector<string> test3_inputs;
  string test3_expectedOutput = "No parametrs\n";
  bool test3_passed = runTest(test3_inputs, test3_expectedOutput);
  cout << "Test 3: " << (test3_passed ? "Passed\n" : "Failed\n") << endl;

  // Тест 4: Проверка работы программы для 5 параметров
  vector<string> test4_inputs = { "param1", "param2", "param3", "param4", "param5" };
  string test4_expectedOutput = "Цикл while:\nparam5\nparam4\nparam3\nparam2\nparam1\n----------------------\nЦикл for:\nparam5\nparam4\nparam3\nparam2\nparam1\n";
  bool test4_passed = runTest(test4_inputs, test4_expectedOutput);
  cout << "Test 4: " << (test4_passed ? "Passed\n" : "Failed\n") << endl;

 return 0;
}