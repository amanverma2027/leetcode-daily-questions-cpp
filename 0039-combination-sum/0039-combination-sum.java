class Solution {
    private void findcombination(int ind, int[] candidates,int target, List<List<Integer>>ans,List<Integer>ds){
        if(target==0){
            ans.add(new ArrayList<>(ds));
            return;
        }
        if(ind==candidates.length)
        return;

        if(candidates[ind]<=target){
            ds.add(candidates[ind]);
            findcombination(ind,candidates,target-candidates[ind],ans,ds);
            ds.remove(ds.size()-1);
        }
            findcombination(ind+1,candidates,target,ans,ds);
        }
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>>ans=new ArrayList<>();
        List<Integer>ds=new ArrayList<>();
        findcombination(0,candidates,target,ans,ds);
        return ans;
    }
}