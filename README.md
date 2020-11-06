# ShortCircuitEval

# Check if compiler optimisation doesn't change the below behaviour - validating subsequent conditions should be ommited if a condition is met:
# -> 'short-circuit evaluation' guarantees the wanted behaviour:
# Checked on vs2019; Linux g++ (20201010, wd)
# Quote: Short-circuit evaluation, minimal evaluation, or McCarthy evaluation (after John McCarthy) is the semantics of some Boolean
#        operators in some programming languages in which the second argument is executed or evaluated only if the first argument
#        does not suffice to determine the value of the expression: when the first argument of the AND function evaluates to false,
#        the overall value must be false; and when the first argument of the OR function evaluates to true, the overall value must
#        be true.
