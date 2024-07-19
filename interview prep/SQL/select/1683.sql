--length is a function that return tha length od string

select tweet_id from Tweets
where length(content)>15;