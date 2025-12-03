public class ATM
{
    private long[] count;
    private readonly int[] vals = { 20, 50, 100, 200, 500 };

    public ATM()
    {
        count = new long[5];
    }

    public void Deposit(int[] banknotesCount)
    {
        for (int i = 0; i < 5; i++)
        {
            count[i] += banknotesCount[i];
        }
    }

    public int[] Withdraw(int amount)
    {
        int[] used = new int[5];

        // greedy: use larger bills first
        for (int i = 4; i >= 0; i--)
        {
            if (amount <= 0) break;

            long canUse = Math.Min(count[i], amount / vals[i]);
            used[i] = (int)canUse;
            amount -= (int)(canUse * vals[i]);
        }

        if (amount != 0)
        {
            return new int[] { -1 };
        }

        for (int i = 0; i < 5; i++)
        {
            count[i] -= used[i];
        }

        return used;
    }
}
