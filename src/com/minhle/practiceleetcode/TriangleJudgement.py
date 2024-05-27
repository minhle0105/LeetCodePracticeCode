import pandas as pd

def triangle_judgement(triangle: pd.DataFrame) -> pd.DataFrame:
    x_values = list(triangle['x'])
    y_values = list(triangle['y'])
    z_values = list(triangle['z'])
    is_triangle = []
    for i in range(len(x_values)):
        cond_1 = x_values[i] + y_values[i] > z_values[i]
        cond_2 = y_values[i] + z_values[i] > x_values[i]
        cond_3 = z_values[i] + x_values[i] > y_values[i]
        is_triangle.append("Yes" if (cond_1 and cond_2 and cond_3) else "No")
    
    res = {'x': x_values, 'y': y_values, 'z': z_values, 'triangle': is_triangle}
    return pd.DataFrame(res)
