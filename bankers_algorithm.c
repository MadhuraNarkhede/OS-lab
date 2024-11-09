Practical no. 08
#include <iostream>
using namespace std;
void Bankers(int need[][10], int available[], int allocated[][10], int p, int n)
{
int n_available[n];
bool finish[p] = { false };
int safeSeq[p];
int count = 0;
for (int i = 0; i < n; i++)
{
n_available[i] = available[i];
}
while (count < p)
{
bool found = false;
for (int i = 0; i < p; i++)
{
if (!finish[i])
{
bool canAllocate = true;
for (int j = 0; j < n; j++)
{
if (need[i][j] > n_available[j])
{
canAllocate = false;
break;
}
}
if (canAllocate)
{
for (int j = 0; j < n; j++)
{
n_available[j] += allocated[i][j];
}
safeSeq[count++] = i;
finish[i] = true;
found = true;
}
}
}
if (!found)
{
cout << "\nSystem is not in a safe state." << endl;
return;
}
}
cout << "System is in a safe state.\nSafe Sequence is: ";
for (int i = 0; i < p; i++)
{
cout << safeSeq[i] << " ";
}
cout << endl;
}
int main()
{
int i, j, n;
cout << "\nEnter the number of Resources: ";
cin >> n;
int t_resource[n];
cout << "\nEnter the instances of Resources:" << endl;
for (i = 0; i < n; i++)
{
cout << "R" << i + 1 << ": ";
cin >> t_resource[i];
}
int p;
cout << "\nEnter the Number of Processes: ";
cin >> p;
int allocated[p][10], max[p][10], need[p][10];
int t_allocated[10] = {0}, available[10];
cout << "\nEnter the values of Allocated matrix: " << endl;
for (i = 0; i < p; i++)
{
for (j = 0; j < n; j++)
{
cin >> allocated[i][j];
}
}
cout << "\nAllocated Matrix" << endl;
for (i = 0; i < p; i++)
{
for (j = 0; j < n; j++)
{
cout << allocated[i][j] << " ";
}
cout << endl;
}
cout << "\nEnter the values of Max matrix: " << endl;
for (i = 0; i < p; i++) {
for (j = 0; j < n; j++)
{
cin >> max[i][j];
}
}
for (i = 0; i < p; i++)
{
for (j = 0; j < n; j++)
{
need[i][j] = max[i][j] - allocated[i][j];
}
}
cout << "\nNeed Matrix" << endl;
for (i = 0; i < p; i++)
{
for (j = 0; j < n; j++)
{
cout << need[i][j] << " ";
}
cout << endl;
}
for (j = 0; j < n; j++)
{
for (i = 0; i < p; i++)
{
t_allocated[j] += allocated[i][j];
}
}
cout << "\nTotal Allocated" << endl;
for (i = 0; i < n; i++)
{
cout << t_allocated[i] << " ";
}
for (i = 0; i < n; i++)
{
available[i] = t_resource[i] - t_allocated[i];
}
cout << "\nAvailable: " << endl;
for (i = 0; i < n; i++)
{
cout << available[i] << " ";
}
Bankers(need, available, allocated, p, n);
return 0;
}
/*
OUTPUT:
codebind@CODEBIND:~$ g++ BankersAlgorithm.cpp
codebind@CODEBIND:~$ ./a.out
Enter the number of Resources: 3
Enter the instances of Resources:
R1: 10
R2: 5
R3: 7
Enter the Number of Processes: 5
Enter the values of Allocated matrix:
0 1 0
3 0 2
3 0 2
2 1 1
0 0 2
Allocated Matrix
0 1 0
3 0 2
3 0 2
2 1 1
0 0 2
Enter the values of Max matrix:
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
Need Matrix
7 4 3
0 2 0
6 0 0
0 1 1
4 3 1
Total Allocated
8 2 7
Available:
2 3 0 System is in a safe state.
Safe Sequence is: 1 3 4 0 2
*/
