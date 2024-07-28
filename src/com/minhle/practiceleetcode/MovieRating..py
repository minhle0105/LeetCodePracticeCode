import pandas as pd

def movie_rating(movies: pd.DataFrame, users: pd.DataFrame, movie_rating: pd.DataFrame) -> pd.DataFrame:
    movie_ids = list(movie_rating['movie_id'])
    m_user_ids = list(movie_rating['user_id'])
    ratings = list(movie_rating['rating'])
    
    movie_rating['created_at'] = pd.to_datetime(movie_rating['created_at'])
    
    years = movie_rating['created_at'].dt.year
    months = movie_rating['created_at'].dt.month
    
    movie_info = construct_info_mapping(movies, 'movie')
    user_info = construct_info_mapping(users, 'user')

    review_per_users = dict()
    max_review_per_user = 0

    for i in range(len(m_user_ids)):
        if m_user_ids[i] not in review_per_users:
            review_per_users[m_user_ids[i]] = 0
        review_per_users[m_user_ids[i]] += 1
        max_review_per_user = max(max_review_per_user, review_per_users[m_user_ids[i]])
    
    user_ids_with_max_reviews = []

    for pairs in review_per_users.items():
        if pairs[1] == max_review_per_user:
            user_ids_with_max_reviews.append(pairs[0])

    user_names_with_max_reviews = [user_info[id_] for id_ in user_ids_with_max_reviews]
    user_names_with_max_reviews = sorted(user_names_with_max_reviews)

    name_res = user_names_with_max_reviews[0]

    ratings_per_movie = dict()
    for i in range(len(ratings)):
        if years[i] == 2020 and months[i] == 2:
            if movie_ids[i] not in ratings_per_movie:
                ratings_per_movie[movie_ids[i]] = []
            ratings_per_movie[movie_ids[i]].append(ratings[i])
    
    average_ratings_per_movie = dict()
    max_avg_rating = 0.0
    for pairs in ratings_per_movie.items():
        total_rating = 0
        for r in pairs[1]:
            total_rating += r
        average_ratings_per_movie[pairs[0]] = total_rating / len(pairs[1])
        max_avg_rating = max(max_avg_rating, average_ratings_per_movie[pairs[0]])
    
    movie_ids_with_highest_avg_rating = []
    for pairs in average_ratings_per_movie.items():
        if pairs[1] == max_avg_rating:
            movie_ids_with_highest_avg_rating.append(pairs[0])
    
    movie_names_with_highest_avg_rating = [movie_info[id_] for id_ in movie_ids_with_highest_avg_rating]
    movie_names_with_highest_avg_rating = sorted(movie_names_with_highest_avg_rating)

    res = {'results': [name_res, movie_names_with_highest_avg_rating[0]]}
    return pd.DataFrame(res)
    
def construct_info_mapping(df, name):
    mapping = dict()
    ids = []
    names = []
    if name == 'movie':
        ids = list(df['movie_id'])
        names = list(df['title'])
    else:
        ids = list(df['user_id'])
        names = list(df['name'])
    for i in range(len(names)):
        mapping[ids[i]] = names[i] 
    return mapping

    
