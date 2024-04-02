using System.Collections;

namespace data.structures.console.Collections;

public class DynamicArray<T> : IEnumerable<T>
{
    const int initialCapacity = 10;
    private T[] _items;
    private int _count;

    public int Count => 
        _count;
        
    public DynamicArray()
    {
        _items = new T[initialCapacity];
        _count = 0;
    }

    public DynamicArray(int size)
    {
        if (size < 0)
            throw new ArgumentOutOfRangeException(nameof(size), "Size must be non-negative.");

        _items = new T[size];
        _count = 0;
    }

    public void Add(T item) 
    {
        if (_items.Length == _count) 
            Resize();

        var index = _count;

        _items[index] = item;
        _count++;
    }

    public void Remove(T item) 
    {
        if (_items.Length == _count * 2)
            Resize();

        int index = 0;

        while (index < _count) {

            if (_items[index]!.Equals(item))
                break;

            index++;
        }

        for (int i = index; i < _count - 1; i++) 
        {
            _items[i] = _items[i + 1];
        }

        _count--;
    }

    private void Resize()
    {
        var newArray = new T[_count + initialCapacity];

        for (int i = 0; i < _count; i++)
            newArray[i] = _items[i];

        _items = newArray;
    }

    public IEnumerator<T> GetEnumerator()
    {
        for (int i = 0; i < _count; i++)
            yield return _items[i];
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }
}