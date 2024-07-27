import pandas as pd

def tree_node(tree: pd.DataFrame) -> pd.DataFrame:
    ids = list(tree['id'])
    p_ids = list(tree['p_id'])
    graph = dict()
    root = -1

    for i in range(len(ids)):
        if str(p_ids[i]) == "<NA>":
            root = ids[i]
        else:
            node = ids[i]
            parent = p_ids[i]
            if node not in graph:
                graph[node] = []
            if parent not in graph:
                graph[parent] = []
            graph[parent].append(node)

    res = dict()
    for id_ in ids:
        if id_ == root:
            res[id_] = 'Root'
        else:
            res[id_] = 'Leaf' if len(graph[id_]) == 0 else 'Inner'
    
    return pd.DataFrame(data=res.items(), columns=['id', 'type'])
