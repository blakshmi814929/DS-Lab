/*Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence 
of ch (inclusive). If the character ch does not exist in word, do nothing.*/
#include<stdio.h>
#include<string.h>
char* reversePrefix(char* word, char ch)
{
    int idx = -1;
    int len = strlen(word);
    for(int i=0;i<len;i++)
    {
        if(word[i]==ch)
        {
            idx = i;
            break;
        }
    }
    if(idx==-1)
        return word;
    int left = 0;
    int right = idx;
    while(left<right)
    {
        char temp = word[left];
        word[left] = word[right];
        word[right] = temp;
        left++;
        right--;
    }
    return word;
}
int main()
{
    char word[20];
    char ch;
    printf("Enter a string: ");
    scanf("%s",word);
    printf("Enter a character: ");
    scanf(" %c",&ch);
    printf("Original : %s\n",word);
    printf("Modified : %s\n",reversePrefix(word,ch));
    return 0;
}
