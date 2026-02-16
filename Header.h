#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

void task1();
void findAns(int** table, int N, int B, int* c, int& volume, int* d, int** count);

void task2();
void Solve(int n, int** a, int** b);
void steps(std::string& motion, int n, int** b);

void task3();
int input_k(int k);
int input_n(int n);
int checking_usl(int n, int k, int change);
