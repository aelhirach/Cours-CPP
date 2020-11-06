#include <cstring>
#include <iostream>
#include <iomanip>
#include "list.h"
#include "algo.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ws;
using std::setw;
using std::left;
using namespace StructInfoList;
using namespace StructInfoAlgo;

int Compare(int i1, int i2);

int main(int argc, char** argv)
{
    int a0[] = {};
    list<int> l0;
    l0.insert(l0.end(),a0,a0);
    cout << seqToString(a0,a0+0) << " and " << seqToString(a0,a0+0)  << " -> " << seqCompare(a0,a0,a0,a0,Compare) << endl;
    cout << seqToString(l0.begin(),l0.end()) << " and " << seqToString(l0.begin(),l0.end())  << " -> " << seqCompare(l0.begin(),l0.end(),l0.begin(),l0.end(),Compare) << endl;
    cout << seqToString(l0.begin(),l0.end()) << " and " << seqToString(a0,a0)  << " -> " << seqCompare(l0.begin(),l0.end(),a0,a0,Compare) << endl;
    int a1[] = {1};
    list<int> l1;
    l1.insert(l1.end(),a1,a1+1);
    cout << seqToString(a1,a1+1) << " and " << seqToString(a1,a1+1)  << " -> " << seqCompare(a1,a1+1,a1,a1+1,Compare) << endl;
    cout << seqToString(l1.begin(),l1.end()) << " and " << seqToString(l1.begin(),l1.end())  << " -> " << seqCompare(l1.begin(),l1.end(),l1.begin(),l1.end(),Compare) << endl;
    cout << seqToString(l1.begin(),l1.end()) << " and " << seqToString(a1,a1+1)  << " -> " << seqCompare(l1.begin(),l1.end(),a1,a1+1,Compare) << endl;
    int a2[] = {4,5,1,1,4,5,1,0};
    list<int> l2;
    l2.insert(l2.end(),a2+1,a2+7);
    cout << seqToString(a2,a2+8) << " and " << seqToString(l2.begin(),l2.end())  << " -> " << seqCompare(a2,a2+8,l2.begin(),l2.end(),Compare) << endl;
    cout << seqToString(l2.begin(),l2.end()) << " and " << seqToString(a2,a2+8)  << " -> " << seqCompare(l2.begin(),l2.end(),a2,a2+8,Compare) << endl;
    cout << seqToString(a2+1,a2+7) << " and " << seqToString(l2.begin(),l2.end())  << " -> " << seqCompare(a2+1,a2+7,l2.begin(),l2.end(),Compare) << endl;
    cout << seqToString(l2.begin(),--l2.end()) << " and " << seqToString(l2.begin(),l2.end())  << " -> " << seqCompare(l2.begin(),--l2.end(),l2.begin(),l2.end(),Compare) << endl;
    cout << seqToString(l2.begin(),l2.end()) << " and " << seqToString(++l2.begin(),l2.end())  << " -> " << seqCompare(l2.begin(),l2.end(),++l2.begin(),l2.end(),Compare) << endl;
    cout << seqToString(++l2.begin(),--l2.end()) << " and " << seqToString(a2+2,a2+6)  << " -> " << seqCompare(++l2.begin(),--l2.end(),a2+2,a2+6,Compare) << endl;
    cout << seqToString(a2,a2+3) << " and " << seqToString(a2+4,a2+7)  << " -> " << seqCompare(a2,a2+3,a2+4,a2+7,Compare) << endl;
    cout << seqToString(a2,a2+4) << " and " << seqToString(a2+4,a2+7)  << " -> " << seqCompare(a2,a2+4,a2+4,a2+7,Compare) << endl;
}

int Compare(int i1, int i2)
{
    return (i1 - i2);
}

