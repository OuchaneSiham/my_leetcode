

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int wordLen = strlen(words[0]);
    int totalLen = wordLen * wordsSize;
    int sLen = strlen(s);
    int* result = (int*)malloc(sLen * sizeof(int));
    *returnSize = 0;

    if (sLen < totalLen) {
        return result;
    }
    int* wordCount = (int*)calloc(wordsSize, sizeof(int));
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < wordsSize; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                wordCount[i]++;
            }
        }
    }
    for (int i = 0; i <= sLen - totalLen; i++) {
        int* currentCount = (int*)calloc(wordsSize, sizeof(int));
        int j = 0;
        for (; j < wordsSize; j++) {
            char* sub = (char*)malloc((wordLen + 1) * sizeof(char));
            strncpy(sub, s + i + j * wordLen, wordLen);
            sub[wordLen] = '\0';
            int k;
            for (k = 0; k < wordsSize; k++) {
                if (strcmp(sub, words[k]) == 0) {
                    currentCount[k]++;
                    break;
                }
            }
            free(sub);
            if (k == wordsSize || currentCount[k] > wordCount[k]) {
                break;
            }
        }
        if (j == wordsSize) {
            result[(*returnSize)++] = i;
        }
        free(currentCount);
    }

    free(wordCount);
    return result;
}
