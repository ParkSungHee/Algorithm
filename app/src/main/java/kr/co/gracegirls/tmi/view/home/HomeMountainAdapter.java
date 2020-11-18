package kr.co.gracegirls.tmi.view.home;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.data.item.MountainListItem;

public class HomeMountainAdapter extends RecyclerView.Adapter<HomeMountainAdapter.HomeMountainViewHolder> {

    private List<MountainListItem> mountainList;
    private Context context;
    private MountainListItem data;

    public HomeMountainAdapter(Context context, List<MountainListItem> list) {
        this.context = context;
        this.mountainList = list;
    }

    @NonNull
    @Override
    public HomeMountainViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        return new HomeMountainViewHolder(LayoutInflater.from(parent.getContext()).inflate(R.layout.item_mountain_list, parent, false));
    }

    @Override
    public void onBindViewHolder(@NonNull HomeMountainViewHolder holder, int position) {
        data = mountainList.get(position);
        holder.title.setText(data.getTitle());
        holder.location.setText(data.getLocation());
        holder.riskPoint.setText(data.getRiskPoint() + "");
    }

    @Override
    public int getItemCount() {
        return mountainList.size();
    }

    class HomeMountainViewHolder extends RecyclerView.ViewHolder {

        private TextView title, riskPoint, location;

        public HomeMountainViewHolder(@NonNull View itemView) {
            super(itemView);
            this.title = itemView.findViewById(R.id.mountain_title);
            this.riskPoint = itemView.findViewById(R.id.mountain_risk_point);
            this.location = itemView.findViewById(R.id.mountain_location);
        }
    }
}
