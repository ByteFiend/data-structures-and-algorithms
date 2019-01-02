class Solution {
public:
  /*
   * @param string: An array of Char
   * @param length: The true length of the string
   * @return: The true length of new string
   */
  int replaceBlank(char string[], int length) {
    if (NULL == string || length <= 0) { return 0; }

    int spaceCnt = 0;
    for (int i = 0; i < length; ++i){
      if (' ' == string[i]) { ++spaceCnt; }
    }

    int newLength = length + (spaceCnt << 1);
    string[newLength] = '\0';
    int i = newLength - 1, j = length - 1;
    while (i >= 0 && j >= 0){
      if (' ' == string[j]) {
        string[i--] = '0';
        string[i--] = '2';
        string[i--] = '%';
      } else {
        string[i--] = string[j];
      }
      --j;
    }

    return newLength;
  }
};
