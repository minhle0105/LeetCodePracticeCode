import pandas as pd

def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    scores = list(scores['score'])
    scores = sorted(scores, reverse=True)
    if len(scores) == 0:
        res = {'score': [], 'rank': []}
        return pd.DataFrame(res)
    ranks = [1]
    for i in range(1, len(scores)):
        ranks.append(ranks[-1] + (0 if scores[i] == scores[i - 1] else 1))
    res = {'score': scores, 'rank': ranks}
    return pd.DataFrame(res)
