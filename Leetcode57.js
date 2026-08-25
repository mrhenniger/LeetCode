// LeetCode 57. Insert Interval
//
// You are given an array of non-overlapping intervals intervals where
// intervals[i] = [start_i, end_i] represent the start and the end of the ith
// interval, and intervals is sorted in ascending order by start_i. You are also
// given an interval newInterval = [start, end].
//
// Insert newInterval into intervals such that intervals is still sorted in
// ascending order by start_i and still does not have any overlapping intervals
// (merge overlapping intervals if necessary).
//
// Return intervals after the insertion. You don't need to modify intervals
// in-place; you can make a new array and return it.

/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function (intervals, newInterval) {

    // There is nothing already in the intervals, so we just return the new interval as the only interval.
    if (intervals.length === 0) {
        return [newInterval];
    }

    // Check for the case where the new interval is before all existing intervals, and there is no overlap.
    if(newInterval[1] < intervals[0][0]) {
        return [newInterval, ...intervals];
    }
    
    // Check for the case where the new interval is after all existing intervals, and there is no overlap.
    if(newInterval[0] > intervals[intervals.length - 1][1]) {
        return [...intervals, newInterval];
    }

    // Stash the intervals in a return array until we find the first overlap
    let i = 0;
    const result = [];
    while (i < intervals.length &&  intervals[i][1] < newInterval[0]) {
        result.push(intervals[i]);
        i++;
    }
    //console.log("head", result);

    // May be in the middle with no overlap
    if (newInterval[1] < intervals[i][0]) {
        result.push(newInterval);
        //console.log("middle 1", result);
    }

    // Loop to merge new newInterval with any overlapping intervals (new interval consumes)
    else {
        while (i < intervals.length && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
            newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push(newInterval);
        //console.log("middle 2", result);
    }
    
    // Add any remaining intervals that are after the new interval
    while (i < intervals.length) {
        result.push(intervals[i]);
        i++;
    }

    return result;
};

function main() {
    console.log("Test Case - Before the first interval, no overlap");
    print(insert([[3, 4], [5, 6]], [1, 2]));                             // [[1,2],[3,4],[5,6]]

    console.log("Test Case - After the last interval, no overlap");
    print(insert([[1, 2], [3, 4]], [5,6]));                             // [[1,2],[3,4],[5,6]]

    console.log("Test Case - In the middle, no overlap");
    print(insert([[1, 2], [5, 6]], [3,4]));                             // [[1,2],[3,4],[5,6]]

    console.log("Test Case - Overlap in the middle with one to the left");
    print(insert([[1, 2], [3, 4],[7,8],[9,10]], [4,5]));                // [[1,2],[3,5],[7,8],[9,10]]

    console.log("Test Case - Overlap in the middle with one to the right");
    print(insert([[1, 2], [3, 4],[7,8],[9,10]], [6,7]));                // [[1,2],[3,4],[6,8],[9,10]]

    console.log("Test Case - Overlap in the middle, exact match");
    print(insert([[1, 2], [4, 5], [7,8], [10,11], [13,13]], [7,8]));    // [[1, 2], [4, 5], [7,8], [10,11], [13,13]]

    console.log("Test Case - Overlap in the middle, consume one");
    print(insert([[1, 2], [4, 5], [7,8], [10,11], [13,13]], [6,9]));    // [[1, 2], [4, 5], [6,9], [10,11], [13,13]]

    console.log("Test Case - Overlap in the middle, consume two");
    print(insert([[1, 2], [4, 5], [7,8], [10,11], [13,13]], [6,12]));    // [[1, 2], [4, 5], [6,12], [13,13]]

    console.log("Test Case 1");
    print(insert([[1, 3], [6, 9]], [2, 5]));                             // [[1,5],[6,9]]

    console.log("Test Case 2");
    print(insert([[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]], [4, 8]));  // [[1,2],[3,10],[12,16]]

    console.log("Test Case 3");
    print(insert([], [5, 7]));                                           // [[5,7]]

    console.log("Test Case 4");
    print(insert([[3, 5], [8, 10]], [1, 2]));                            // [[1,2],[3,5],[8,10]]

    console.log("Test Case 5");
    print(insert([[1, 5]], [2, 3]));                                     // [[1,5]]
}

function print(intervals) {
    console.log("[" + intervals.map(i => "[" + i.join(",") + "]").join(",") + "]");
}

main();
