// C program for KMP Algorithm

#include <stdio.h>
#include <string.h>

// Function to compute LPS array
void computeLPSArray(char* pat, int M, int* lps) {
    int len = 0; // length of the previous longest prefix suffix
    lps[0] = 0; // lps[0] is always 0
    int i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Search Algorithm
void KMPSearch(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
    int j = 0; // index for pat[]

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == M) {
            printf("Found pattern at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

// Driver code
int main() {
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}
