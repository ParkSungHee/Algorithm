package kr.co.gracegirls.tmi.view.shelter;

import android.text.Layout;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.data.ShelterLIstItem;

public class ShelterListAdapter extends RecyclerView.Adapter<ShelterListAdapter.ShelterListViewHolder> {

    private List<ShelterLIstItem> shelterLIstItems;
    private ShelterLIstItem data;

    public ShelterListAdapter(List<ShelterLIstItem> shelterLIstItems) {
        this.shelterLIstItems = shelterLIstItems;
    }

    @NonNull
    @Override
    public ShelterListViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        return new ShelterListViewHolder(LayoutInflater.from(parent.getContext()).inflate(R.layout.item_shelter_list, parent, false));
    }

    @Override
    public void onBindViewHolder(@NonNull ShelterListViewHolder holder, int position) {
        data = shelterLIstItems.get(position);
        holder.title.setText(data.getTitle());
        holder.location.setText(data.getLocation());
        holder.al.setText(data.getAl());
        holder.tmp.setText(data.getTmp());
    }

    @Override
    public int getItemCount() {
        return shelterLIstItems.size();
    }

    class ShelterListViewHolder extends RecyclerView.ViewHolder {

        private TextView title, location, al, tmp;

        public ShelterListViewHolder(@NonNull View itemView) {
            super(itemView);
            this.title = itemView.findViewById(R.id.shelter_title);
            this.location = itemView.findViewById(R.id.shelter_location);
            this.al = itemView.findViewById(R.id.shelter_location_al);
            this.tmp = itemView.findViewById(R.id.shelter_tmp);
        }
    }
}
