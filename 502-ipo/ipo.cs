using System;
using System.Collections.Generic;

public class Solution {
    public int FindMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int n = profits.Length;
        List<Tuple<int, int>> projects = new List<Tuple<int, int>>();
        for (int i = 0; i < n; i++) {
            projects.Add(new Tuple<int, int>(capital[i], profits[i]));
        }

        projects.Sort((a, b) => a.Item1.CompareTo(b.Item1));

        var availableProfits = new PriorityQueue<int, int>(Comparer<int>.Create((a, b) => b.CompareTo(a)));
        
        int projectIndex = 0;

        for (int i = 0; i < k; i++) {
            while (projectIndex < n && projects[projectIndex].Item1 <= w) {
                availableProfits.Enqueue(projects[projectIndex].Item2, projects[projectIndex].Item2);
                projectIndex++;
            }

            if (availableProfits.Count == 0) {
                break;
            }

            w += availableProfits.Dequeue();
        }

        return w;
    }
}