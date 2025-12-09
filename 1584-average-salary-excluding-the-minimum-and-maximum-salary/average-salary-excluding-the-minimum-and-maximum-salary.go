func average(salary []int) float64 {
    minS, maxS := salary[0], salary[0]
    sum := 0

    for _, s := range salary {
        sum += s
        if s < minS {
            minS = s
        }
        if s > maxS {
            maxS = s
        }
    }

    sum -= minS + maxS
    return float64(sum) / float64(len(salary)-2)
}