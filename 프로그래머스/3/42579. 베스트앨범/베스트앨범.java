import java.util.*;

class Solution {
    static class Song implements Comparable<Song> {
        int id;
        int plays;
        
        public Song(int id, int plays) {
            this.id = id;
            this.plays = plays;
        }
        
        @Override
        public int compareTo(Song other) {
            if (this.plays == other.plays) {
                return this.id - other.id;
            }
            return other.plays - this.plays;
        }
    }
    
    public int[] solution(String[] genres, int[] plays) {
        
        Map<String, Integer> genreCount = new HashMap<>();
        Map<String, ArrayList<Song>> genreSongs = new HashMap<>();
        
        for (int i=0;i<genres.length;i++) {
            String genre = genres[i];
            int play = plays[i];
            
            genreCount.put(genre, genreCount.getOrDefault(genre, 0) + play);
            if (!genreSongs.containsKey(genre)) {
                genreSongs.put(genre, new ArrayList<>());
            }
            genreSongs.get(genre).add(new Song(i, play));
        }
        
        List<String> sortedGenres = new ArrayList<>(genreCount.keySet());
        sortedGenres.sort((a, b) -> genreCount.get(b) - genreCount.get(a));
        
        ArrayList<Integer> result = new ArrayList<>();
        
        for (String genre : sortedGenres) {
            List<Song> songs = genreSongs.get(genre);
            Collections.sort(songs);
            for (int i=0;i<songs.size() && i < 2; i++) {
                result.add(songs.get(i).id);
            }
        }
        
        return result.stream().mapToInt(i -> i).toArray();
    }
}