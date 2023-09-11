#include <cstdlib>
#include <iostream>


/*
  Hash function from: http://stackoverflow.com/questions/8317508/hash-function-for-a-string
and was copied as instructed in the write up
 */
unsigned int RSHash(const std::string& str)
{
    unsigned int b    = 378551;
    unsigned int a    = 63689;
    unsigned int hash = 0;

    for(std::size_t i = 0; i < str.length(); i++)
    {
        hash = hash * a + str[i];
        a    = a * b;
    }

    return (hash & 0x7FFFFFFF);
 }

unsigned int JSHash(const std::string& str)
{
      unsigned int hash = 1315423911;

      for(std::size_t i = 0; i < str.length(); i++)
      {
          hash ^= ((hash << 5) + str[i] + (hash >> 2));
      }

      return (hash & 0x7FFFFFFF);
 }
//end of material from

//call the found RSHash() and adapt it to the table size
unsigned int hash1(const std::string s, const int tableSize){
  return( RSHash(s)%tableSize );
}

//call the found JSHash() and adapt it to the table size
unsigned int hash2(const std::string s, const int tableSize){
  return( JSHash(s)%tableSize );
}


int main (int argc, char* argv[])
{

  
  int i;
  i =3;
  std::cout << RSHash("aaaaaaaaaaaaaaaaaRRRRRRRRRRRRRRRRRRRRR") << std::endl;
  std::cout << JSHash("aaaaaaaaaaaaaaaaaRRRRRRRRRRRRRRRRRRRRR") << std::endl;
  std::cout <<  hash1("aaaaaaaaaaaaaaaaaRRRRRRRRRRRRRRRRRRRRR",11) << std::endl;
  std::cout <<  hash2("aaaaaaaaaaaaaaaaaRRRRRRRRRRRRRRRRRRRRR",11) << std::endl;
}
