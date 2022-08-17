This is an algorithm and you'll have to remember it using the intution shared below:
**from left find last less than element** . from the left side find the last element that is smaller than it's next element.
(example : 1, 2, 3, 4, 5) 4 is our element. If none element is smaller than it's next element it means the array is last in it's permutation hence return, it's reverse.
(example : 5, 4, 3, 2, 1 -> return 1, 2, 3, 4, 5)
​
**from right find first element greater than previous step element** . from the right side find the element that is just greater than element found in step 1.
​
**swap them both**
**reverse the array from left of the element found in step 1 till the end**
​
return your array this is your next permutation, say thanks to **narayan pandit**
***we are indeed standing on the shoulders of the giant***