# 209poll
{EPITECH} | Second year | Math project

Several months before an important election, many polls seem to pop up from nowhere. Their interpretations are often surrounded by uncertainty: to what extent are these polls reliable? Why are there so many differences between poll institutes? And from day to day? Is a 3% variation significant? etc...

To estimate the accuracy of the results, a confidence interval is given. It is defined by the fact that there is a x% probability that this interval encompasses the true value.

You already know that questioning people follows a Bernoulli process, and therefore that a binomial distribution (converging toward a normal distribution) is a good model for the results. You can then easily compute the confidence intervals, knowing that:
 - the 95% confidence interval amplitude is 2 ×1.96√v
 - the 99% confidence interval amplitude is 2 ×2.58√v

where v stands for the variance of the sample proportion (corrected for finite populations).
The goal of this project is to compute the 95% and 99% confidence intervals.

See the subject for further details !

========================

Grade : A | Mark : 19

| Category                  | Percentage | Tests     | Crash ? |
|---------------------------|------------|-----------|---------|
| basic                     | 100%       | 2/2       | x       |
| confidence (eval)         | 100%       | 4/4       | x       |
| confidence (intermediate) | 100%       | 4/4       | x       |
| mathematical rigor        | 75%        | 3/4       | x       |
| rigor                     | 100%       | 9/9       | x       |
| **End score**             | **95.7%**  | **22/23** | **No**  |

Made with Quentin TREHEUX ([LuciferBahamut](https://github.com/LuciferBahamut))

Beware of -42 Epitech students !!!
