// multiple levels of indirection

#include<stdio.h>

int main()
{

//A first array is an array of strings used to hold a list of book titles.
  char *titles[] = {"A Tale of Two Cities",
                    "Wuthering Heights","Don Quixote",
                    "Odyssey","Moby-Dick","Hamlet",
                    "Gulliver's Travels"};

  /*
  Two additional array are provided whose purpose is to maintain a list of best books and English books.
  Instead of holding copies of the titles , they will hold the 
  address of title in titles array.
  Both arrays will need to be decalred as a pointer to a pointer to a char.
  The array's element hold the address of the titles array's elements.
  This will avoid having to duplicate memory for each title and result in a single location for titles.
  */                    
  char **bestBooks[3];
  char **englishBooks[4];

  bestBooks[0] = &titles[0];
  bestBooks[1] = &titles[3];
  bestBooks[2] = &titles[5];

  englishBooks[0] = &titles[0];
  englishBooks[1] = &titles[1];
  englishBooks[2] = &titles[5];
  englishBooks[3] = &titles[6];


  //if a title needs to be changed , 
  //then the change will only have to be performed in one location.
  printf("%s\n",*englishBooks[1]);  // Wuthering Heights

  return 0;
}
