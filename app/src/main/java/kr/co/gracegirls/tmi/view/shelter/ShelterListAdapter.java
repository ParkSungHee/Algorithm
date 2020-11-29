package kr.co.gracegirls.tmi.view.shelter;

import android.annotation.SuppressLint;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.data.item.ShelterListItem;

public class ShelterListAdapter extends RecyclerView.Adapter<ShelterListAdapter.ShelterListViewHolder> {

    private List<ShelterListItem> shelterListItems;
    private ShelterListItem data;

    public ShelterListAdapter(List<ShelterListItem> shelterListItems) {
        this.shelterListItems = shelterListItems;
    }

    @NonNull
    @Override
    public ShelterListViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        return new ShelterListViewHolder(LayoutInflater.from(parent.getContext()).inflate(R.layout.item_shelter_list, parent, false));
    }

    @SuppressLint("SetTextI18n")
    @Override
    public void onBindViewHolder(@NonNull ShelterListViewHolder holder, int position) {
        data = shelterListItems.get(position);
        holder.title.setText(data.getName());
        holder.location.setText(data.getAddress());
        holder.latitude.setText(data.getLatitude());
        holder.longitude.setText(data.getLongitude());
        holder.height.setText(data.getHeight() + "m");
        holder.people.setText(data.getPeople() + "명");
    }

    @Override
    public int getItemCount() {
        return shelterListItems.size();
    }

    class ShelterListViewHolder extends RecyclerView.ViewHolder {

        private TextView title, location, latitude, longitude, height, people;

        public ShelterListViewHolder(@NonNull View itemView) {
            super(itemView);
            this.title = itemView.findViewById(R.id.shelter_title);
            this.location = itemView.findViewById(R.id.shelter_location);
            this.latitude = itemView.findViewById(R.id.shelter_latitude_pos);
            this.longitude = itemView.findViewById(R.id.shelter_longitude_pos);
            this.height = itemView.findViewById(R.id.shelter_height_pos);
            this.people = itemView.findViewById(R.id.shelter_people_count);
        }
    }
}
