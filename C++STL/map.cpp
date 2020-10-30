int main (){
  map<char,int> anom;
                           
  anom['a']=10;
  anom['b']=20;
  anom['c']=30;
  anom['d']=40;

   map<char, int>::iterator it;

   for(it = anom.begin() ; it! = anom.end() ; ++it){   //iterating through the map
      cout << it->first << " => " << it->second << '\n';
   }

  return 0;
}
