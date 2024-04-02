namespace data.structures.console.Models;

public record Person(string Name) 
{
    public override string ToString()
    {
        return Name;
    }
}

