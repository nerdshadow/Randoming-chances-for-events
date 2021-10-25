#include <iostream>
#include <vector>

float randomto(int i)
{
    int x = 101 + i, alpha = 2417, m = 13;
    int M = 1000;
    int r =((alpha * x + m) % M);
    float result = r;
    return result / M;
}

//----- sample
//for (int i = 0; i < 10; i++)
//{
//    std::cout << randomto(i) << std::endl;
//}

void EventProbability()
{
    int amount;
    std::cout <<"Insert amount of events: ";

    std::cin >> amount;
    std::cout << std::endl;

    std::vector<double> arrayOfChances;
    double chance;
    for ( int i = 0; i < amount; i++)
    {
        std::cout << "Insert chance of event # "<< i+1 <<" is: ";
        std::cin >> chance;
        std::cout << std::endl;
        arrayOfChances.push_back(chance);
    }
    float randomed = 0;
    for (int i = 0; i < amount; i++)
    {
     
        randomed = randomto(i + randomed);
        
        std::cout << "Chance of event # "<<i+1 << " is: "<<std::endl;
        if (randomed <= arrayOfChances[i])
        {
            std::cout << "Event # " << i + 1 << " is successful cause " << arrayOfChances[i] << " >= " << randomed << std::endl;
        }
        else
        {
            std::cout << "Event # " << i + 1 << " is unsuccessful cause " << arrayOfChances[i] << " < " << randomed << std::endl;
        }
    }
}

void ConnectedEventProbability()
{   
    std::vector<double> arrayOfEvent2Chances;
    std::vector<float> arrayOfRandomNumbers;
    double chance;
    double firstEvent;
    
    std::cout << "Insert chance of event # 1 is: ";
    std::cin >> chance;
    std::cout << std::endl;
    firstEvent = chance;
    
    std::cout << "Insert chance of event # 2 if event # 1 is successful: ";
    std::cin >> chance;
    std::cout << std::endl;
    arrayOfEvent2Chances.push_back(chance);
    
    std::cout << "Insert chance of event # 2 if event # 1 is unsuccessful: ";
    std::cin >> chance;
    std::cout << std::endl;
    arrayOfEvent2Chances.push_back(chance);

    float randomed = 0;
    for (int i = 0; i < 3; i++)
    {
        randomed = randomto(i + randomed);
        arrayOfRandomNumbers.push_back(randomed);
    }
    
    if (firstEvent >= arrayOfRandomNumbers[0])
    {
        std::cout << "Event # 1 is successful cause: " << firstEvent << " >= " << arrayOfRandomNumbers[0] << std::endl <<"Then: "<<std::endl;
        if (arrayOfEvent2Chances[0] >= arrayOfRandomNumbers[1])
        {
            std::cout << "Event # 2 is successful cause: " << arrayOfEvent2Chances[0] << " >= " << arrayOfRandomNumbers[1] << std::endl;
        }
        else
        {
            std::cout << "Event # 2 is unsuccessful cause: " << arrayOfEvent2Chances[0] << " < " << arrayOfRandomNumbers[1] << std::endl;
        }
    }
    else
    {
        std::cout << "Event # 1 is unsuccessful cause: " << firstEvent << " <= " << arrayOfRandomNumbers[0] << std::endl << "Then: " << std::endl;
        if (arrayOfEvent2Chances[1] >= arrayOfRandomNumbers[2])
        {
            std::cout << "Event # 2 is successful cause: " << arrayOfEvent2Chances[1] << " >= " << arrayOfRandomNumbers[2] << std::endl;
        }
        else
        {
            std::cout << "Event # 2 is unsuccessful cause: " << arrayOfEvent2Chances[1] << " < " << arrayOfRandomNumbers[2] << std::endl;
        }
    }

}

int main()
{
    EventProbability();             //random chances for an events

    ConnectedEventProbability();    //random chance for two events if they connected
   
    system("pause");
}

