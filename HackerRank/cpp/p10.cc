#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


// Function to count consecutive 1s in a binary string
int countConsecutiveOnes(const string& binaryString) {
    int maxConsecutiveOnes = 0;
    int currentConsecutiveOnes = 0;

    for (char bit : binaryString) {
        if (bit == '1') {
            currentConsecutiveOnes++;
            // Update maxConsecutiveOnes if the current sequence is longer
            if (currentConsecutiveOnes > maxConsecutiveOnes) {
                maxConsecutiveOnes = currentConsecutiveOnes;
            }
        } else {
            // Reset currentConsecutiveOnes when encountering '0'
            currentConsecutiveOnes = 0;
        }
    }

    return maxConsecutiveOnes;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
    
     // Convert decimal number to binary string
    string binaryString = bitset<sizeof(int) * 8>(n).to_string();

    // Trim leading zeros from binary string (optional)
    binaryString.erase(0, min(binaryString.find_first_not_of('0'), binaryString.size() - 1));

    // Count consecutive 1s in the binary string
    int consecutiveOnesCount = countConsecutiveOnes(binaryString);

    // Output the binary representation and consecutive 1s count
    //cout << "Binary representation of " << n << " is: " << binaryString << endl;
    cout << consecutiveOnesCount << endl;
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

