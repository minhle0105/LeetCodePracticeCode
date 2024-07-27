import pandas as pd

def find_unique_email_domains(emails: pd.DataFrame) -> pd.DataFrame:
    all_emails = list(emails['email'])
    all_domains = [get_domain(all_emails[i]) for i in range(len(all_emails))]
    counter = dict()
    for domain in all_domains:
        length = len(domain)
        if domain[length - 4 :] == ".com":
            if domain in counter:
                counter[domain] += 1
            else:
                counter[domain] = 1
    counter = dict(sorted(counter.items(), key=lambda item: item[0]))
    return pd.DataFrame(list(counter.items()), columns=['email_domain', 'count'])

def get_domain(email):
    for i in range (len(email)):
        if email[i] == '@':
            return email[i + 1 :]
