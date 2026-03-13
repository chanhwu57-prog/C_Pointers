#include <stdio.h>
#include <string.h>

static char *ones[] = {
    "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
    "seventeen", "eighteen", "nineteen"
};

static char *tens[] = {
    "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

static char *scales[] = {
    "", "thousand", "million", "billion"
};

void write_hundreds(unsigned int n, char *buffer) {
    if (n >= 100) {
        sprintf(buffer + strlen(buffer), "%s hundred", ones[n / 100]);
        n %= 100;
        if (n > 0) {
            strcat(buffer, " ");
        }
    }
    
    if (n >= 20) {
        strcat(buffer, tens[n / 10]);
        n %= 10;
        if (n > 0) {
            strcat(buffer, "-");
            strcat(buffer, ones[n]);
        }
    } else if (n > 0) {
        strcat(buffer, ones[n]);
    }
}

void written_amount(unsigned int amount, char *buffer) {
    if (amount == 0) {
        strcpy(buffer, "zero");
        return;
    }
    
    buffer[0] = '\0';
    
    int scale_index = 0;
    char temp[1000];
    char result[1000] = "";
    
    while (amount > 0) {
        int chunk = amount % 1000;
        if (chunk > 0) {
            temp[0] = '\0';
            write_hundreds(chunk, temp);
            
            if (scale_index > 0) {
                strcat(temp, " ");
                strcat(temp, scales[scale_index]);
            }
            
            if (strlen(result) > 0) {
                strcat(temp, " ");
                strcat(temp, result);
            }
            strcpy(result, temp);
        }
        amount /= 1000;
        scale_index++;
    }
    
    strcpy(buffer, result);
}

int main(void) {
    char buffer[1000];
    
    written_amount(0, buffer);
    printf("0: %s\n", buffer);
    
    written_amount(5, buffer);
    printf("5: %s\n", buffer);
    
    written_amount(15, buffer);
    printf("15: %s\n", buffer);
    
    written_amount(42, buffer);
    printf("42: %s\n", buffer);
    
    written_amount(100, buffer);
    printf("100: %s\n", buffer);
    
    written_amount(123, buffer);
    printf("123: %s\n", buffer);
    
    written_amount(1234, buffer);
    printf("1234: %s\n", buffer);
    
    written_amount(12345, buffer);
    printf("12345: %s\n", buffer);
    
    written_amount(1234567, buffer);
    printf("1234567: %s\n", buffer);
    
    return 0;
}
