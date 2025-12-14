/**
 * @param {string} corridor
 * @return {number}
 */
var numberOfWays = function(corridor) {
    const MOD = 1_000_000_007;
    let seatCount = 0;
    let ways = 1;
    let plantsBetween = 0;
    let pairCompleted = false;

    for (const ch of corridor) {
        if (ch === 'S') {
            seatCount++;
            if (seatCount % 2 === 0) {
                pairCompleted = true;
            } 
            else if (pairCompleted) {
                ways = (ways * (plantsBetween + 1)) % MOD;
                plantsBetween = 0;
                pairCompleted = false;
            }
        } else if (pairCompleted) {
            plantsBetween++;
        }
    }

    return seatCount > 0 && seatCount % 2 === 0 ? ways : 0;
};