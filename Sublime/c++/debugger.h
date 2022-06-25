#pragma once
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x <<" "; __print(x); cerr<<endl;

void __print(int x) {cerr << x;}
void __print(long long x) { cerr << x;}
void __print(double x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(string x) {cerr << x;}
void __print(char x) {cerr << x;}

template <typename T> void __print(vector<T> x) {cerr << "[ "; for (T i : x) {__print(i); cerr << ",";} cerr << " ],";}
template <typename T> void __print(set<T> x) {cerr << "[ "; for (T i : x) {__print(i); cerr << ",";} cerr << " ],";}
template <typename T> void __print(unordered_set<T> x) {cerr << "[ "; for (T i : x) {__print(i); cerr << ",";} cerr << " ],";}
template <typename T> void __print(list<T> x) {cerr << "[ "; for (T i : x) {__print(i); cerr << ",";} cerr << " ],";}
template <typename T> void __print(multiset<T> x) {cerr << "[ "; for (T i : x) {__print(i); cerr << ",";} cerr << " ],";}

template <typename T, typename V> void __print(pair<T, V> x) {cerr << "{ " << x.first << "," << x.second << " }";}
template <typename T, typename V> void __print(map<T, V> x) {cerr << "[ "; for (pair<T, V> i : x) {__print(i); cerr << ",";} cerr << " ],";}
