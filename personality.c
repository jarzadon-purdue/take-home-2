// personality.c - Student implementation file
// Implement the personality scoring logic described in the README.

#include <ctype.h>
#include "personality.h"

static int roundNearest(double value) {
    return (int) (value + 0.5);
}

int getDimensionIndex(int questionIndex) {
    int temp;
    temp = questionIndex % 7;
    int out;
    if (temp == 0) {
        out = 0;
    } else if ((temp == 1) || (temp == 2)) {
        out = 1;
    } else if ((temp == 3) || (temp == 4)) {
        out = 2;
    } else if ((temp == 5) || (temp == 6)) {
        out = 3;
    }
    return out;
}

void countAnswers(const char * answers,
                  int aCounts[NUM_DIMENSIONS],
                  int bCounts[NUM_DIMENSIONS]) {
    // initialize arrays

    for (int i = 0; i < NUM_DIMENSIONS; i++) {
        aCounts[i] = 0;
    }
    for (int j = 0; j < NUM_DIMENSIONS; j++) {
        bCounts[j] = 0;
    }

    int dimension;
    // loop through answers
    for (int questionIndex = 0; questionIndex < NUM_QUESTIONS; questionIndex++) {
        dimension = getDimensionIndex(questionIndex);
        if ((answers[questionIndex] == 'A') || (answers[questionIndex] == 'a')) {
            aCounts[dimension]++;
        } else if ((answers[questionIndex] == 'B') || (answers[questionIndex] == 'b')) {
            bCounts[dimension]++;
        }
    }
}

int computePercentageB(int aCount, int bCount) {
    if ((aCount == 0) && (bCount == 0)) {
        return -1;
    }
    double percent;
    percent = (((double) bCount) / (((double) aCount) + ((double) bCount))) * 100;
    return roundNearest(percent);
}

char determinePersonalityLetter(int dimension, int percentageB) {
    // TODO: Implement this function
    char letters[4][2] = {
        {'E', 'I'},
        {'S', 'N'},
        {'T', 'F'},
        {'J', 'P'}
    };

    char output;
    int side;

    if (percentageB == -1) {
        output = '-';
    } else if (percentageB == 50) {
        output = 'X';
    } else {
        if (percentageB < 50) {
            side = 0;
        } else {
            side = 1;
        }
        
        output = letters[dimension][side];
    }

    return output;
}

PersonalityResult analyzeAnswers(const char * answers) {
    PersonalityResult result;

    int aCounts[NUM_DIMENSIONS];
    int bCounts[NUM_DIMENSIONS];
    countAnswers(answers, aCounts, bCounts);

    // TODO: Implement this function
    for (int i = 0; i < NUM_DIMENSIONS; i++) {
        
        result.percentages[i] = computePercentageB(aCounts[i], bCounts[i]);
        result.personalityType[i] = determinePersonalityLetter(i, result.percentages[i]);
    }
    result.personalityType[NUM_DIMENSIONS] = '\0';

    return result;
}
