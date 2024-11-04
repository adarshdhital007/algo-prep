class Solution {
    public String predictPartyVictory(String senate) {
        //two queue
        Queue<Integer> rQ = new LinkedList<>();
        Queue<Integer> dQ = new LinkedList<>();

        for(int i=0;i<senate.length();i++){
            if(senate.charAt(i) == 'R'){
                rQ.add(i);
            }else{
                dQ.add(i);
            }
        }

        while(!rQ.isEmpty() && !dQ.isEmpty()){
            int rIndex = rQ.poll();
            int dIndex = dQ.poll();

            if(rIndex < dIndex){
                rQ.add(rIndex + senate.length());
            }
            else{
                dQ.add(dIndex + senate.length());
            }
        }
        return rQ.isEmpty() ? "Dire" : "Radiant";
    }
}