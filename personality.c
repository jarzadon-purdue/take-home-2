// personality.c - Student implementation file
// Implement the personality scoring logic described in the README.

#include <ctype.h>
#include "personality.h"

static int roundNearest(double value) {
    return (int) (value + 0.5);
}

int getDimensionIndex(int questionIndex) {
    // TODO: Implement this function
    return 0;
}

void countAnswers(const char * answers,
                  int aCounts[NUM_DIMENSIONS],
                  int bCounts[NUM_DIMENSIONS]) {
    // TODO: Implement this function
}

int computePercentageB(int aCount, int bCount) {
    // TODO: Implement this function. Use roundNearest() to round the percentage.
    return roundNearest(0);
}

char determinePersonalityLetter(int dimension, int percentageB) {
    // TODO: Implement this function
    return '-';
}

PersonalityResult analyzeAnswers(const char * answers) {
    PersonalityResult result;

    // TODO: Implement this function
    for (int i = 0; i < NUM_DIMENSIONS; i++) {
        result.percentages[i] = -1;
        result.personalityType[i] = '-';
    }
    result.personalityType[NUM_DIMENSIONS] = '\0';

    return result;
}
