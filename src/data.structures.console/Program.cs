
using data.structures.console.Collections;

var list = new DynamicArray<int>();

for (int i = 1; i <= 80; i++) 
    list.Add(i);

foreach(var item in list)
{
    Console.WriteLine(item);
}

for (int i = 15; i <= 60; i++) 
    list.Remove(i);

foreach(var item in list)
{
    Console.WriteLine(item);
}