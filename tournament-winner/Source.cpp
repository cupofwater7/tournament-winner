#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


const int Home_Team_Won = 1;
void UpdateScore(string team, int point, unordered_map<string, int >& scores);
string tournamentWinner(vector<vector<string>> competitions, vector<int> results);


void main() 
{
   
        vector<vector<string>> competitions = {
            {"HTML", "C#"}, {"C#", "Python"}, {"Python", "HTML"} };
        vector<int> results = { 0, 0, 1 };
        cout << tournamentWinner(competitions, results);
        
}


string tournamentWinner(vector<vector<string>> competitions, vector<int> results)
{
    string currentBestTeam = "";
    unordered_map<string, int> scores = { {currentBestTeam,0} };
    // Write your code here.
    for (int i = 0; i < results.size(); i++)
    {
        auto result = results[i];
        auto competition = competitions[i];
        auto homeTeam = competition[0];
        auto awayTeam = competition[1];
        auto winningTeam = result == Home_Team_Won ? homeTeam : awayTeam;

        UpdateScore(winningTeam, 3, scores);

        if (scores[winningTeam] > scores[currentBestTeam])
        {
            currentBestTeam = winningTeam;
        }
    }
    return currentBestTeam;
}


void UpdateScore(string team, int point, unordered_map<string, int >& scores)
{
    if (scores.find(team) == scores.end())
    {
        scores[team] = 0;
    }

    scores[team] += point;
}