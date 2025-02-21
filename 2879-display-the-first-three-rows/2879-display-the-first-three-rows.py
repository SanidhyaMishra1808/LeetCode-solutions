import pandas as pd

def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
    #xyz = employees.head(3)  #xyz is a datafram which we have created
    return employees.head(3)