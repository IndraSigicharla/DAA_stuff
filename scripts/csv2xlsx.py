import sys
import pandas as pd

csvfile = sys.argv[1]

df = pd.read_csv(csvfile)
df.to_excel(f'{csvfile[:-4]}.xlsx', index = False)
