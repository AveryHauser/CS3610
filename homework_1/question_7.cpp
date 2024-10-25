// template <class elemType>
// int arrayListType<elemType>::seqSearch(const elemType& item) const
// {
//     int loc;
//     bool found = false;
//     for (loc = 0; loc < length; loc++)
//     if (list[loc] == item)
//     {
//     found = true;
//     break;
//     }
//     if (found)
//     return loc;
//     else
//     return -1;
// } //end seqSearch

//Sequential search with recurtion 
template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item, int loc) const{

    //If the amount of times were going through the recution is over the length of item 
    //it will just return -1
    if (loc >= length) return -1;

    // if what we are searching for is found then we return the ocation of the item
    if (item[loc] == length) return loc;

    //will iterate through until one of the base cases happen
    return seqSearch(item, loc + 1);

}